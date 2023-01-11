<?PHP
//DATABASE CONNECTION INFORMATION
$host = "sql202.epizy.com";
$user = "epiz_33003979";
$password = "G5PEUtFzXuE";
$dbname = "epiz_33003979_project";
$db = mysqli_connect($host, $user, $password, $dbname);
// Check connection
if (mysqli_connect_errno()) {
	echo "Failed to connect to MySQL: " . mysqli_connect_error();
	exit();
}
echo "Connected successfully";
?>