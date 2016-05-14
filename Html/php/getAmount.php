<?php
	include 'functions.php';
	if( !checkToken() ){
		exit("Unauthorized");
	}
	$connection = connect();
	session_start();
	$username = $_SESSION['Username'];
	session_commit();
	$query = "SELECT Amount FROM accounts WHERE Username='$username' OR Email='$username'";
	$result = mysqli_query($connection,$query) or die("Error");
	$count = mysqli_num_rows($result);
	if($count > 0){
		$row = mysqli_fetch_array($result);
		setlocale(LC_MONETARY, 'it_IT');
		if(function_exists("money_format")){
			echo money_format('%.2n', $row[0]);
		}else{
			echo $row[0];
		}
		
	}else{
		echo "Error";
	}
?>