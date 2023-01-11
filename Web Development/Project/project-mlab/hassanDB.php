<?php
// define const of db information
define("DB_HOST", "sql202.epizy.com");
define("DB_USER", "epiz_33003979");
define("DB_PASSWORD", "G5PEUtFzXuE");
define("DB_DATABASE", "epiz_33003979_project");

// Create connection
$db = mysqli_connect(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);

// Check connection
if (!$db) {
    die("<body> Connection failed: " . mysqli_connect_error() . "</body> </html>");
}

function test_input($data)
{
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
}
?>