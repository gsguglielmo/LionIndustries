<?php
	include 'functions.php';
	if( !checkToken() ){
		exit("Unauthorized");
	}
	$connection = connect();
	$query = "SELECT * FROM receipeList WHERE 1";
	$result = mysqli_query($connection,$query) or die("Error");
	$count = mysqli_num_rows($result);
	$final = "";
	$model = '	<div id="#ID#desc" class="poput">
					<div class="row">
						<div class="col-xs-2">
						</div>
						<div class="col-xs-8">
							<br>
							<center>
								<h3 id="naslov">#TITLE#</h3>
								<br>
								<h4>#DESC#</h4>
							</center>
							<br>
							<ul>
								#INGREDIENTS#
							</ul>
						</div>
						<div class="col-xs-2">
							<center>
								<i id="close" class="fa fa-times"></i>
							</center>
						</div>
					</div>
				</div>';
	for ($i=0; $i < $count; $i++) { 
		$row = mysqli_fetch_array($result);
		$tmp = str_replace("#TITLE#", $row[1], $model);
		$tmp = str_replace("#ID#", "rec".$row[0], $tmp);
		$tmp = str_replace("#DESC#", $row[2], $tmp);
		$query = "SELECT * FROM Receipe WHERE NomeRicetta='$row[1]'";
		$result2 = mysqli_query($connection,$query) or die("Error");
		$count2 = mysqli_num_rows($result2);
		$final2 = "";
		for ($j=0; $j < $count2; $j++){
			$row2 = mysqli_fetch_array($result2);
			$final2 .= "<li>".$row2[2]."</li>";
		}
		$tmp = str_replace("#INGREDIENTS#", $final2, $tmp);
		$final .= $tmp;
	}
	echo $final;
?>