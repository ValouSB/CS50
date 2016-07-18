<?php
    require("../includes/config.php");
    if ($_SERVER["REQUEST_METHOD"] == "GET")   render("register_form.php", ["title" => "Register"]); 
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["username"]) or empty($_POST["password"]) or empty($_POST["confirmation"])) apologize("All fields must be complete");
        else if ($_POST["password"] != $_POST["confirmation"]) apologize("Passwords are differents");
        else 
        {
            $query = CS50::query("INSERT IGNORE INTO users (username, hash, cash) VALUES(?, ?, 10000.0000)", $_POST["username"], password_hash($_POST["password"], PASSWORD_DEFAULT));
            if ($query === 0) apologize("username already exist");
            else
            {
                $rows = CS50::query("SELECT LAST_INSERT_ID() AS id");
                $id = $rows[0]["id"];
                $_SESSION["id"] = $id;
                redirect("/");     
            }
        }
    }
?>