<?php
    require(__DIR__ . "/../includes/config.php");
    $places = [];
    $geo = explode(" ", trim(str_replace(",", " ", $_GET["geo"])));
    $count = count($geo);
    if ($count < 1) print("Count must be > than 1");
    elseif ($count === 1)
    {
    	$geo = $geo[0];
    	if(strlen($geo) === 5) $places = CS50::query("SELECT * FROM places WHERE postal_code = ?", $geo);	
    	elseif(strlen($geo) == 2)	$places = CS50::query("SELECT * FROM places WHERE admin_code1 = ?", strtoupper($geo));
    	else $places = CS50::query("SELECT * FROM places WHERE place_name LIKE ?", $geo);
    	if(empty($places))	$places = CS50::query("SELECT * FROM places WHERE admin_name1 LIKE ?", $geo);
    }
    else
    {
    	$geo = implode(" ", $geo);
    	$places = CS50::query("SELECT * FROM places WHERE MATCH(postal_code, place_name, admin_name1, admin_code1) AGAINST (?)", $geo);
    }
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));
?>