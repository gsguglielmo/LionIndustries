<?php
	include 'functions.php';
	session_start();
	$username = $_SESSION["Username"];
	echo $_SESSION["Username"]."<br>".$_SESSION["Authentication"]."<br>";
	$connection = connect();
	$query = "SELECT Token,Password FROM accounts WHERE Username='$username' OR Email='$username'";
	$result = mysqli_query($connection,$query) or die("Error2");
	$count = mysqli_num_rows($result);	
	if($count == 1){
		$row = mysqli_fetch_array($result);
		$tmp = $username.$row[0].$row[1];
		echo "<br>".$tmp."<br>".hash("sha512", $tmp);
	}

?>