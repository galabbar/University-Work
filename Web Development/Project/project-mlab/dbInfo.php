<?PHP
/*	 Rania online infinity free DB
//DATABASE CONNECTION INFORMATION
$host = "sql202.epizy.com";
$user = "epiz_33003991";
$dbpassword = "lCyumAPIPC";
$dbname = "epiz_33003991_mlabdb";
$db = mysqli_connect($host, $user, $dbpassword, $dbname);
// Check connection
if (mysqli_connect_errno())
{
echo "Failed to connect to MySQL: " . mysqli_connect_error();
exit();
}
//echo "Connected successfully";*/


// Team online infinity free


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


?>