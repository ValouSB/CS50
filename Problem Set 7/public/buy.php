<?php
    require("../includes/config.php");
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["stock"]) || empty($_POST["amount"])) apologize("You must give a stock and an amount.");
        $stock = lookup($_POST["stock"]);
        if ($stock === false)  apologize("Invalid stock.");
        $total = $stock["price"] * $_POST["amount"];
        $rows = CS50::query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
        $bank = $rows[0]["cash"];
        if ($bank < $total)  apologize("Sorry, you don't have enough money.");
        else
        {   
            $update_stocks = CS50::query("INSERT INTO stocks (id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], $stock["symbol"], ($_POST["amount"]));
            if ($update_stocks === false) apologize("SQL Error 1.");
            $shares = $_POST["amount"];
            $update_cash = CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $total,  $_SESSION["id"]);
            if ($update_cash === false)   apologize("SQL Error 2");
            $history = CS50::query("INSERT INTO history(id, type, symbol, shares, price, date) VALUES (?, ?, ?, ?, ?, Now())", $_SESSION["id"], "bought", strtoupper($stock["symbol"]), $_POST["amount"], $stock["price"]);
            if ($history === false)   apologize("SQL Error 3");
            redirect("/");
        }
    }  
    else
    {
        $rows = CS50::query("SELECT symbol FROM stocks WHERE id = ?", $_SESSION["id"]);
        render("buy_form.php", ["title" => "Buy"]);
    }
?>