<?php
    require("../includes/config.php");
    if ($_SERVER["REQUEST_METHOD"] == "GET")   render("change_password_form.php", ["title" => "Register"]); 
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["old_password"]) or empty($_POST["password"]) or empty($_POST["confirmation"])) apologize("All fields must be complete");
        else if ($_POST["password"] != $_POST["confirmation"]) apologize("Passwords are differents");
        else if ($_POST["password"] == $_POST["old_password"]) apologize ("Your new password must be different from the old one.");
        else 
        {
            $rows = CS50::query("SELECT hash FROM users WHERE id = ?", $_SESSION["id"]);
            $row = $rows[0];
            if (password_verify($_POST["old_password"], $row["hash"]))
            {
                $pass = password_hash($_POST["password"], PASSWORD_DEFAULT) ;
                $id = $_SESSION["id"];
                $query = CS50::query("UPDATE users SET hash='$pass' WHERE id='$id'");
                redirect("/");
            }
            else apologize("Current password is invalid.");
        }
    }
?>