<?php
	if(isset($_POST['sender'])){
		include 'functions.php';
		$username = $_POST['Username'];
		$password = $_POST['Password'];
		$name = $_POST['Name'];
		$surname = $_POST['Surname'];
		$email = $_POST['Email'];
		$gender = $_POST['Gender'];
		if($gender=="M"){
			$g = 1;
		}else{
			$g = 0;
		}
		$connection = connect();
		$connection = switchMain($connection);
		$query = "INSERT INTO accounts (Username,Password,Email,Name,Surname,Gender) VALUES ('$username','$password','$email','$name','$surname',$g)";
		echo $query."\n";
		mysqli_query($connection,$query) or die("NO");
		echo "OK";
	}
?>