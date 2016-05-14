<?php
	include 'functions.php';
	if( !checkToken() ){
		exit("Unauthorized");
	}
	$connection = connect();
	$query = "SELECT * FROM receipeList WHERE 1";
	$result = mysqli_query($connection,$query) or die("ErrorA");
	$count = mysqli_num_rows($result);
	$final = "";
	$model = '	<div class="row cocktailDiv">
					<div class="col-xs-8">
						<h3>#TITLE#</h3>
					</div>
					<div class="col-xs-2">
						<i class="info fa fa-info-circle fa-3x" id="#ID#"></i>
					</div>
					<div id="buy" class="col-xs-2">
						<center>
							<a href="">
								<i class="fa fa-arrow-right fa-3x" id="#ID#"></i>
							</a>
						</center>
					</div>
				</div>';
	for ($i=0; $i < $count; $i++) { 
		$row = mysqli_fetch_array($result);
		$tmp = str_replace("#TITLE#", $row[1], $model);
		$tmp = str_replace("#ID#", "rec".$row[0], $tmp);
		$final .= $tmp;
	}
	echo $final;
?>