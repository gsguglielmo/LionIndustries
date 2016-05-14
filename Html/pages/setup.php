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
	<link rel="stylesheet" type="text/css" href="CSS/setup.css">
	<link rel="stylesheet" href="../font-awesome-4.3.0/css/font-awesome.min.css">
	<script src="../javascript/jquery.min.js"></script>
	<script src="../bootstrap/js/bootstrap.min.js"></script>

</head>
<body>
	
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
				<div class="queue col-xs-2">
					<center>
						<a href="">CODA</a>
					</center>
				</div>
			</div>
		<div id="content">
			<div id="logoSetup">
				<center>
					<i class="fa fa-cogs fa-5x" aria-hidden="true"></i>
					<h2>SETUP</h2>
					<div class="line"></div>
				</center>
			</div>
            <!--ALCOL-->
            <!--ALCOL-->
            <!--ALCOL-->
            <!--ALCOL-->

			<center>
				<h3 id="alcolTitle">BEVANDE ALCOLICHE</h3>
			</center>
			<!--setupdiv-->
			<div id="alcol1" class="row cocktailDiv">
				<div class="col-xs-2">
					<center>
						<h3 class="number">1.</h3>						
					</center>
				</div>
				<div class="col-xs-6">
					<input class="alcolName" type="text" name="firstname" value="Alcol name">
				</div>
				<div class="col-xs-4">
					<input class="alcolQty" type="text" name="firstname" value="QTY">
					<h3 class="QTY">ml</h3>
				</div>
			</div>
			<!--setupdiv-->
			<div id="alcol2" class="row cocktailDiv">
				<div class="col-xs-2">
					<center>
						<h3 class="number">2.</h3>						
					</center>
				</div>
				<div class="col-xs-6">
					<input class="alcolName" type="text" name="firstname" value="Alcol name">
				</div>
				<div class="col-xs-4">
					<input class="alcolQty" type="text" name="firstname" value="QTY">
					<h3 class="QTY">ml</h3>
				</div>
			</div>
			<!--setupdiv-->
			<div id="alcol3" class="row cocktailDiv">
				<div class="col-xs-2">
					<center>
						<h3 class="number">3.</h3>						
					</center>
				</div>
				<div class="col-xs-6">
					<input class="alcolName" type="text" name="firstname" value="Alcol name">
				</div>
				<div class="col-xs-4">
					<input class="alcolQty" type="text" name="firstname" value="QTY">
					<h3 class="QTY">ml</h3>
				</div>
			</div>
			<!--setupdiv-->
			<div id="alcol4" class="row cocktailDiv">
				<div class="col-xs-2">
					<center>
						<h3 class="number">4.</h3>						
					</center>
				</div>
				<div class="col-xs-6">
					<input class="alcolName" type="text" name="firstname" value="Alcol name">
				</div>
				<div class="col-xs-4">
					<input class="alcolQty" type="text" name="firstname" value="QTY">
					<h3 class="QTY">ml</h3>
				</div>
			</div>
			<!--setupdiv-->
			<div id="alcol5" class="row cocktailDiv">
				<div class="col-xs-2">
					<center>
						<h3 class="number">5.</h3>						
					</center>
				</div>
				<div class="col-xs-6">
					<input class="alcolName" type="text" name="firstname" value="Alcol name">
				</div>
				<div class="col-xs-4">
					<input class="alcolQty" type="text" name="firstname" value="QTY">
					<h3 class="QTY">ml</h3>
				</div>
			</div>
			<!--setupdiv-->
			<div id="alcol6" class="row cocktailDiv">
				<div class="col-xs-2">
					<center>
						<h3 class="number">6.</h3>						
					</center>
				</div>
				<div class="col-xs-6">
					<input class="alcolName" type="text" name="firstname" value="Alcol name">
				</div>
				<div class="col-xs-4">
					<input class="alcolQty" type="text" name="firstname" value="QTY">
					<h3 class="QTY">ml</h3>
				</div>
			</div>
			<!--setupdiv-->
			<!--ANALCOLIC-->
			<center>
				<h3 id="analcolicTitle">BEVANDE ANALCOLICHE</h3>
			</center>
			<!--setupdiv-->
			<div id="anallcolic1" class="row cocktailDiv">
				<div class="col-xs-2">
					<center>
						<h3 class="number">1.</h3>						
					</center>
				</div>
				<div class="col-xs-6">
					<input class="analcolicName" type="text" name="firstname" value="Analcolic name">
				</div>
				<div class="col-xs-4">
					<input class="analcolicQty" type="text" name="firstname" value="QTY">
					<h3 class="QTY">ml</h3>
				</div>
			</div>
			<!--setupdiv-->
			<div id="anallcolic2" class="row cocktailDiv">
				<div class="col-xs-2">
					<center>
						<h3 class="number">2.</h3>						
					</center>
				</div>
				<div class="col-xs-6">
					<input class="analcolicName" type="text" name="firstname" value="Analcolic name">
				</div>
				<div class="col-xs-4">
					<input class="analcolicQty" type="text" name="firstname" value="QTY">
					<h3 class="QTY">ml</h3>
				</div>
			</div>
			<!--setupdiv-->
			<div id="anallcolic3" class="row cocktailDiv">
				<div class="col-xs-2">
					<center>
						<h3 class="number">3.</h3>						
					</center>
				</div>
				<div class="col-xs-6">
					<input class="analcolicName" type="text" name="firstname" value="Analcolic name">
				</div>
				<div class="col-xs-4">
					<input class="analcolicQty" type="text" name="firstname" value="QTY">
					<h3 class="QTY">ml</h3>
				</div>
			</div>
			<!--setupdiv-->
			<div id="anallcolic4" class="row cocktailDiv">
				<div class="col-xs-2">
					<center>
						<h3 class="number">4.</h3>						
					</center>
				</div>
				<div class="col-xs-6">
					<input class="analcolicName" type="text" name="firstname" value="Analcolic name">
				</div>
				<div class="col-xs-4">
					<input class="analcolicQty" type="text" name="firstname" value="QTY">
					<h3 class="QTY">ml</h3>
				</div>
			</div>
			<!--setupdiv-->
			<div id="anallcolic5" class="row cocktailDiv">
				<div class="col-xs-2">
					<center>
						<h3 class="number">5.</h3>						
					</center>
				</div>
				<div class="col-xs-6">
					<input class="analcolicName" type="text" name="firstname" value="Analcolic name">
				</div>
				<div class="col-xs-4">
					<input class="analcolicQty" type="text" name="firstname" value="QTY">
					<h3 class="QTY">ml</h3>
				</div>
			</div>
			<!--setupdiv-->
			<div id="anallcolic6" class="row cocktailDiv">
				<div class="col-xs-2">
					<center>
						<h3 class="number">6.</h3>						
					</center>
				</div>
				<div class="col-xs-6">
					<input class="analcolicName" type="text" name="firstname" value="Analcolic name">
				</div>
				<div class="col-xs-4">
					<input class="analcolicQty" type="text" name="firstname" value="QTY">
					<h3 class="QTY">ml</h3>
				</div>
			</div>
			<!--setupdiv-->

			<div id="carica">
				<center>
					<input type="button" class="button" value="CARICA">
				</center>
			</div>
		</div>	
	</div>
</body>
</html>