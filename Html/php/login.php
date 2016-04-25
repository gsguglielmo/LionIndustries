<?php
	if(isset($_POST['sender'])){
		include 'functions.php';
		$username = $_POST['Username'];
		$password = $_POST['Password'];
		$connection = connect();
		$query = "SELECT Password FROM accounts WHERE Username='$username' OR Email='$username'";
		$result = mysqli_query($connection,$query) or die("Error2");
		$count = mysqli_num_rows($result);	
		if($count==1){
			$row = mysqli_fetch_array($result);
			if($password == hash("sha512", $row[0])){
				echo "LOGIN OK";
				$token = randomKeyGen(100);
				$query = "Update accounts SET Token='$token' WHERE Username='$username' OR Email='$username'";
				mysqli_query($connection,$query);
				$security = $username + $token + $row[0];
				$security = hash("sha512", $security);
				session_start();
				$_SESSION["Username"]=$username;
				$_SESSION["Authentication"] = $security;
				session_commit();
			}else{
				echo "LOGIN ERROR";
			}
		}else{
			echo "LOGIN ERROR";
		}
	}
?>