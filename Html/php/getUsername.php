<?php
	include 'functions.php';
	if( !checkToken() ){
		exit("Unauthorized");
	}
	$connection = connect();
	session_start();
	$username = $_SESSION['Username'];
	session_commit();
	$query = "SELECT Username FROM accounts WHERE Username='$username' OR Email='$username'";
	$result = mysqli_query($connection,$query) or die("Error");
	$count = mysqli_num_rows($result);
	if($count > 0){
		$row = mysqli_fetch_array($result);
		echo $row[0];
	}else{
		echo "Error";
	}
?>