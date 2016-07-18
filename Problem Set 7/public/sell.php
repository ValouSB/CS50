<?php
    require("../includes/config.php"); 
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["stock"]))  apologize("You must give a stock.");
        if (lookup($_POST["stock"]) === false) apologize("You must give a stock.");
        else
        {   
            $rows = CS50::query("SELECT * FROM stocks WHERE id = ? AND symbol = ?", $_SESSION["id"], strtoupper($_POST["stock"]));
            if ($rows === false) apologize("SQL Error 4.");
            $shares = $rows[0]["shares"];
            $worth = $stock["price"] * $shares;
            $sold = CS50::query("DELETE FROM stocks WHERE id = ? AND symbol = ?", $_SESSION["id"], strtoupper($_POST["stock"]));
            if ($sold === false) apologize("SQL Error 5.");
            $update = CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $_SESSION["id"], $worth);
            if ($update === false)   apologize("SQL Error 6");
            $history = CS50::query("INSERT INTO history (id, type, symbol, shares, price, date) VALUES (?, ?, ?, ?, ?, Now())", $_SESSION["id"], "sold", strtoupper($stock["symbol"]), $shares, $stock["price"]);
            redirect("/");
    
        }
    }    
    else
    {
        $rows = CS50::query("SELECT symbol FROM stocks WHERE id = ?", $_SESSION["id"]);
        render("sell_form.php", ["title" => "Buy", "symbols" => $rows]);
    }
?>