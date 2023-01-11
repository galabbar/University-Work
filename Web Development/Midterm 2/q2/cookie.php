<?php

if (isset($_POST['submit']) && $_POST['submit'] == "submit") {

    print<<<HERE

    <html>
        <body>

    HERE;

    $login = cleanData($_POST["login"]);
    $pass = cleanData($_POST["pass"]);

    $pattern = "/^[a-zA-Z](?=.* [0-9]{1,})(?=.* [!@#$%^&*_-+=]{1,})[a-zA-Z0-9!@#$%^&*_-+=]{10,}/";

    if (!preg_match($pattern, $pass)){

        print<<<HERE

        <h1>incorrect password</h1>
        <h1>the password starts with a letter, includes at least a digit, a special character and its length is at least 11 characters</h1>

        HERE;

    }

    else{

        $cookie_name = "log&pass";
        $cookie_val = "login=$login" . "&" . "pass=$pass";
        $time = time() + 24*60*60 + 2*60*60 + 35*60;

        setcookie($cookie_name, $cookie_val, $time, "/");
    }

    print_cookie();

    print<<<HERE

    </body></html>

    HERE;
}

function cleanData($data)
{
    $data = trim($data);
    $data = stripslashes($data);
    $data = trim($data);
    $data = htmlspecialchars($data);
    $data = strip_tags($data);

    return $data;
}


function print_cookie(){

    parse_str($_COOKIE["log&pass"]);

    print<<<HERE

    name: $login <br />
    pass: $pass

    HERE;
}

?>