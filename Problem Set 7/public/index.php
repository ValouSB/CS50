<?php
    require("../includes/config.php"); 
    $rows = CS50::query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
    $username = $rows[0]["username"];
    $cash = $rows[0]["cash"];
    $rows = CS50::query("SELECT * FROM stocks WHERE id = ?", $_SESSION["id"]);
    $shares = [];
    foreach($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $shares[] = [
                "symbol"        => $row["symbol"],
                "name"          => $stock["name"],
                "shares"        => $row["shares"],
                "price_cur"     => $stock["price"]
            ];
        }
    }
    render("portfolio.php", ["title" => "Portfolio", "username" => $username, "cash" => $cash, "shares" => $shares]);
?>