<?php
include 'credentials.php';

function connect(){
	$connection = mysqli_connect(MYSQL_HOSTNAME,MYSQL_USERNAME,MYSQL_PASSWORD,MYSQL_DATABASE) or die("Connection error");
	return $connection;
}

?>