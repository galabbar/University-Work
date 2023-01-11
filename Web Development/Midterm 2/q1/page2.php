<?php

if (isset($_POST['submit']) && $_POST['submit'] == "submit") {


    $N = (int) cleanData($_POST["N"]);
    $M = (int) cleanData($_POST["M"]);
    $K = (int) cleanData($_POST["K"]);
    $W = (int) cleanData($_POST["W"]);

    print<<<HERE

    <html>
        <body>

    HERE;

    if ($N + $M + $K + $W < 12) {

        print <<<HERE
        
        <h1>the password should be at least 12 character in length. Enter here to try again...</h1>
        <form method="post" action="q1.php">
            <input type="submit">
        </form>
        HERE;
    } else {
        $pass = "";

        $incr = 0;

        for ($i = 0; $i < $N; $i++) {

            if (97 + $incr >= 97 || 97 + $incr <= 122) {

                $pass .= chr(97 + $incr);
                $incr++;
            } else {

                $incr = 0;
            }
        }

        $incr = 0;

        for ($i = 0; $i < $M; $i++) {

            if (65 + $incr >= 65 || 65 + $incr <= 90) {

                $pass .= chr(65 + $incr);
                $incr++;
            } else {

                $incr = 0;
            }
        }
    
        $incr = 0;
        for ($i = 0; $i < $K; $i++) {

            if (48 + $incr >= 48 || 48 + $incr <= 57) {

                $pass .= chr(48 + $incr);
                $incr++;
            } else {

                $incr = 0;
            }
        }
        $incr = 0;
        for ($i = 0; $i < $K; $i++) {

            if (33 + $incr >= 33 || 33 + $incr <= 47) {

                $pass .= chr(33 + $incr);
                $incr++;
            } else {

                $incr = 0;
            }
        }


        print<<<HERE

        <h1>your new password:</h1>
        $pass
        HERE;

    }

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



?>