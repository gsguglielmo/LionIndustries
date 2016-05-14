<?php
include '../php/functions.php';
if( !checkToken() ){
	header('Location: ../');
}
?>
<!DOCTYPE html>
<html>
<head>
	<title>CLICK&DRINK</title>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no">
	<link href='../font/oswald.css' rel='stylesheet' type='text/css'>
	<link href='https://fonts.googleapis.com/css?family=Josefin+Sans:400,100' rel='stylesheet' type='text/css'>
	<link rel="stylesheet" href="../bootstrap/css/bootstrap.min.css">
	<link rel="stylesheet" type="text/css" href="CSS/conto.css">
	<link rel="stylesheet" href="../font-awesome-4.3.0/css/font-awesome.min.css">
	<script src="../javascript/jquery.min.js"></script>
	<script src="../bootstrap/js/bootstrap.min.js"></script>

</head>
<body>
	<script type="text/javascript">
		$(document).ready(function(){
			getAmount();
			getUsername();
			setInterval(function() {
				authenticator();
				getAmount();
			},1000);
			function authenticator(){
				$.post("../php/authenticator.php",{},function(result) {
					if(result=="0"){
						window.location.replace("../");
					}
				});
			};
			function getUsername(){
				$.post("../php/getUsername.php",{},function(result) {
					if(result=="Unauthorized"){
						window.location.replace("../");
					}else if(result=="Error"){
						alert(result);
					}else{
						$("#usernameName").html(result);
						
					}
				});
			};
			function getAmount(){
				$.post("../php/getAmount.php",{},function(result) {
					if(result=="Unauthorized"){
						window.location.replace("../");
					}else if(result=="Error"){
						alert(result);
					}else{
						$("#amount").html(result);
					}
				});
			};
		});
	</script>
	<div class="container-fluid">
		<div id="topBar" class="row">
			<div class="col-xs-2">
				<a href="main.php">
					<i class="fa fa-arrow-left fa-3x" id="freccia" aria-hidden="true"></i>
				</a>
			</div>
			<div class="col-xs-8">
				<center>
					<h2 id="scritta">CLICK&DRINK</h2>
				</center>
			</div>
			<div class="col-xs-2">
			</div>
		</div>
		<div id="content" class="row">
			<div id="logoCash">
				<center>
					<i class="fa fa-usd  fa-5x" aria-hidden="true"></i>
					<h2>CONTO</h2>
					<div class="line"></div>
				</center>
			</div>
			<div id="cash">
				<center id="amount">
					€ 00,00
				</center>
			</div>
			<div id="username">
				<center>
					<h3 id="usernameTitle">USERNAME</h3>
				</center>
				<div id="usernameName">					
					NO USERNAME
				</div>
			</div>

		</div>	
	</div>
</body>
</html>