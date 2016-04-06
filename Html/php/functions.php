<?php
include 'credentials.php';

function connect(){
	$connection = mysqli_connect(MYSQL_HOSTNAME,MYSQL_USERNAME,MYSQL_PASSWORD) or die("Connection error");
	return $connection;
}

function switchMain($connection){
	mysqli_select_db($connection,MAIN_DATABASE) or die("Error while switching to recipe database");
	return $connection;
}

function switchMachine($connection){
	mysqli_select_db($connection,MACHINE_DATABASE) or die("Error while switching to machine database");
	return $connection;
}

function getRecipes($connection,$admin){
	$final = '<div class="row">';
	/*
	if($admin == 1){
		$model = $model."<button type='button' class='btn btn-danger right' style = 'margin-left:3px;' onClick='del(\"#title\")'>Elimina</button>";
	}*/
	$model = '
				<div class="col-sm-6">
					<div class="thumbnail">
						<div class="caption">
							<h3>#title</h3>
								<ul>
									#needs
								</ul>
							<p>
								<button type="button" class="btn btn-success btn-lg btn-block" onClick="add(#num)">
									<span class="glyphicon glyphicon-plus" aria-hidden="true"></span>
								</button>
								#ADMIN
							</p>
						</div>
					</div>
				</div>
	';
	if($admin == 1){
		$tt = '
			<button type="button" class="btn btn-danger btn-lg btn-block" onClick="del(\'#title\')">
				<span class="glyphicon glyphicon-trash" aria-hidden="true"></span>
			</button>
		';
		$model = str_replace("#ADMIN", $tt, $model);
	}else{
		$model = str_replace("#ADMIN", "", $model);
	}
	
	$query = "SHOW TABLES";
	$recipes = mysqli_query($connection,$query) or die("Error while retrieving recipes");
	$recipesQty = mysqli_num_rows($recipes);

	for ($i=0; $i < $recipesQty ; $i++) { 
		
		$row = mysqli_fetch_array($recipes);
		$tmp = str_replace("#title", $row[0], $model);
		$needsTmp = getNeeds($connection,$row[0]);
		$tmp = str_replace("#needs", $needsTmp, $tmp);
		$tmp = str_replace("#num", $i, $tmp);
		$final  .= $tmp;
		//$final  .= $model;
		if((($i+1)%2)==0 && ($i+1)<$recipesQty ){
			$final .= '</div>
						<div class="row">';
		}
	}
	$final .= '</div>';
	return $final;
}


?>