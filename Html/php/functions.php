<?php
include 'credentials.php';

function connect(){
	$connection = mysqli_connect(MYSQL_HOSTNAME,MYSQL_USERNAME,MYSQL_PASSWORD,MYSQL_DATABASE) or die("Connection error");
	return $connection;
}

function checkToken(){
	session_start();
	if(!(isset($_SESSION["Username"]) && isset($_SESSION["Authentication"]))){
		return false;
	}
	$username = $_SESSION["Username"];
	$security = $_SESSION["Authentication"];
	session_commit();
	$connection = connect();
	$query = "SELECT Token,Password FROM accounts WHERE Username='$username' OR Email='$username'";
	$result = mysqli_query($connection,$query) or die("Error2");
	$count = mysqli_num_rows($result);	
	if($count == 1){
		$row = mysqli_fetch_array($result);
		$tmp = $username + $row[0] + $row[1];
		if( $security == hash("sha512", $tmp) ){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
	
}

function randomKeyGen($dolzina){
	$baza = 'abcdefghijklmopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789';
	$randomGeneriranaKoda = '';
	for($i=0;$i<$dolzina;$i++)
	{
		$randomGeneriranaKoda .= $baza[rand(0,strlen($baza)-1)];
	}
	return $randomGeneriranaKoda;
}

?>