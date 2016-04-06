<?php
	if(isset($_POST['sender'])){
		include 'functions.php';
		$username = $_POST['Username'];
		$password = $_POST['Password'];
		$connection = connect();
		$connection = switchMain($connection);
		$query = "SELECT ID FROM accounts WHERE Username='$username' AND Password='$password'";
		$result = mysqli_query($connection,$query) or die("Error2");
		$count = mysqli_num_rows($result);	
		if($count==1){
			echo "LOGIN OK";
		}else{
			echo "LOGIN ERROR";
		}
	}
?>