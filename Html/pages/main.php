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
	<link rel="stylesheet" href="../bootstrap/css/bootstrap.min.css">
	<link rel="stylesheet" type="text/css" href="CSS/main.css">
	<link rel="stylesheet" href="../font-awesome-4.3.0/css/font-awesome.min.css">
	<script src="../javascript/jquery.min.js"></script>
	<script src="../bootstrap/js/bootstrap.min.js"></script>

</head>
<body>
	<script type="text/javascript">
		$(document).ready(function(){
			setInterval(function() {
				authenticator();
			},1000);
		});
		function authenticator(){
			$.post("../php/authenticator.php",{},function(result) {
				if(result=="0"){
					window.location.replace("../");
				}
			});
		};
		function goToCocktail(){
			window.location.replace("cocktail.php");
		}
		function goToAccount(){
			window.location.replace("conto.php");
		}
	</script>
	<div class="container-fluid">
		<div id="topBar" class="row">
			<div class="queue col-xs-2">
				<center>
					<a href="">CODA</a>
				</center>
			</div>
			<div class="col-xs-8">
				<center>
					<h2>CLICK&DRINK</h2>
				</center>
			</div>
			<div class="col-xs-2">
				<a href="">
					<i class="fa fa-cog fa-3x" id="cog" aria-hidden="true"></i>
				</a>
			</div>
		</div>
		<div id="logo-field" class="row">
			<div class="col-xs-12">
				<center>
					<img id="logo" src="../images/logo.jpg">
				</center>
			</div>
		</div>
		<div id="content" class="row">
			<div class="col-xs-6">
			</center>
			<div class="button cocktail" onclick="goToCocktail();">
				<center>
					<i class="fa fa-glass fa-5x"></i><br>
					<p class="text">COCKTAILS</p>
				</center>
			</div>
		</center>
	</div>
	<div class="col-xs-6">
		<center>
			<div class="button conto" onclick="goToAccount();">
				<center>
					<i class="fa fa-usd fa-5x"></i><br>
					<p class="text">CONTO</p>
				</center>
			</div>
		</center>
	</div>
</div>
</div>
<script type="text/javascript">
	var sirina= $('.button').width();
	$('.button').css({'height':sirina+'px;'});
</script>
</body>
</html>