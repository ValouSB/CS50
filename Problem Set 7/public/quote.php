<?php
    require("../includes/config.php"); 
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["stock"]))  apologize("Please enter a stock symbol.");
        $symbol = $_POST["stock"];
        $stock = lookup($symbol);
        $stock2 = $stock["price"];
        if ($stock === false)   apologize("That stock symbol is invalid.");
        else render("quote_display.php", ["title" => "Quote", "symbol" => $symbol, "stock3" => $stock2]);
    }
    else render("quote_form.php", ["title" => "Quote"]);
?>
