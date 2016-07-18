<?php
    require("../includes/config.php"); 
    $rows = CS50::query("SELECT * FROM history WHERE id = ?", $_SESSION["id"]);
    render("history_form.php", ["title" => "History", "symbols" => $rows]);
?>