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
	<link rel="stylesheet" type="text/css" href="CSS/cocktail.css">
	<link rel="stylesheet" href="../font-awesome-4.3.0/css/font-awesome.min.css">
	<script src="../javascript/jquery.min.js"></script>
	<script src="../bootstrap/js/bootstrap.min.js"></script>
	<script>
		$(document).ready(function(){
			getCocktailList();
			getDescriptionList();
			
			setInterval(function() {
				authenticator();
				/*	FIX LIVE UPDATE!!!
				getCocktailList();
				getDescriptionList();
				*/
			},1000);
		});

		function authenticator(){
			$.post("../php/authenticator.php",{},function(result) {
				if(result=="0"){
					window.location.replace("../");
				}
			});
		}

		function updateTriggers () {
			$(".poput").off('click');	
			$(".poput").click(function(){
				$(this).hide('slow');
			});
			$(".info").off('click');	
			$(".info").click(function(){
				var tmp = $(this).attr('id');
				$("#"+tmp+"desc").show('slow');
				//alert("#"+tmp+"desc");
			});
		}

		function getCocktailList () {
			$.post("../php/genCocktailList.php",{},function(result) {
			if(result=="Unauthorized"){
				window.location.replace("../");
			}else if(result=="Error"){
				alert(result);
			}else{
				
				$("#cocktailContainer").html(result);
				updateTriggers();
			}
		});
		}

		function getDescriptionList () {
			$.post("../php/genDescriptionList.php",{},function(result) {
			if(result=="Unauthorized"){
				window.location.replace("../");
			}else if(result=="Error"){
				alert(result);
			}else{
				$("#descriptionContainer").html(result);
				updateTriggers();
			}
		});
		}
	</script>


</head>
<body>

	<div class="container-fluid">
		<div id="topBar" class="row">
				<div class="col-xs-2">
					<a href="">
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
			<div id="logoCocktail">
				<center>
					<i class="fa fa-glass fa-5x"></i><br>
					<h2>COCKTAIL</h2>
					<div class="line"></div>
				</center>
			</div>

					<div id="cocktailContainer">
						<!--cocktails
						<div class="row cocktailDiv">
							<div class="col-xs-8">
								<h3>TITLE</h3>
							</div>
							<div class="col-xs-2">
								<i class="info fa fa-info-circle fa-3x" id="rec1"></i>
							</div>
							<div id="buy" class="col-xs-2">
								<center>
									<a href="">
										<i class="fa fa-arrow-right fa-3x" id="rec1"></i>
									</a>
								</center>
							</div>
						</div>
						cocktails-->
					</div>



					<div id="add" class="row">
						<center>
							<a href="">
								<i class="fa fa-plus fa-4x"></i>
							</a>
						</center>
					</div>
				

			<div id="descriptionContainer">
				
			</div>
			<!--description
			<div id="rec1desc" class="poput">
				<div class="row">
					<div class="col-xs-2">
					</div>
					<div class="col-xs-8">
						<br>
						<center>
							<h3 id="naslov">TITLE</h3>
							<br>
							<h4>DESCRIPTION</h4>
						</center>
						<br>
						<ul>
							<li>ELEMENT</li>
						</ul>
					</div>
					<div class="col-xs-2">
						<center>
							<i id="close" class="fa fa-times"></i>
						</center>
					</div>
				</div>
			</div>
			description-->		

		</div>
	</div>
	<script type="text/javascript">
		
	</script>
</body>
</html>
