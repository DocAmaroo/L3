<!doctype html>

<html>
	
	<head>
		<title> factorielle </title>

		<meta charset="utf-8">
	</head>

  <body>

	<section>
		<form method="get">
			<label for="val">Valeur d'entrée: </label>
			<input type="text" name="val" value="1" pattern="[0-9]+" title="Entiers uniquement"/>
			<input type="submit" value="Envoyer"/>
		
			<p> 
				<?php
					function fact($x){
						return $x <= 1 ? 1 :  $x * fact($x - 1);
					}

					if (isset($_GET["val"])){
						$res = fact($_GET["val"]);
						echo "Fact (".$_GET["val"].")! = ".$res;
					}
				?>
			</p>
		</form>

	</section>

  </body>
</html>