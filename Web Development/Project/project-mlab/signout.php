<?php
session_start();
session_destroy();
echo 'You have been signed out. <a href="index.php">Go back</a>';
?>