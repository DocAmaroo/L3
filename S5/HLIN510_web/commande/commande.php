<!DOCTYPE html>

<html>

<head>

	<title> commande </title>
	<meta charset="utf-8">

</head>

<body>

	<form method="get">

		<?php
			$larticle=array('marteau'=> 10, 'tennaile' => 5, 'vis' => 5.2, 'clou' => 5.8, 'tournevis' => 7, 'ciseau' => 4, 'toile émeri' => 3);
		?>

		<h1> Article </h1>
	
		Quantité : <input type="number" name="quantite" min="0" style="width:50px">
		
		<select size="1" name="article">
			<?php
				foreach ($larticle as $nom => $value) {
					echo "<option>".$nom."</option>";	
				}
			?>
		</select>
		<input type="submit" value="Ajouter" name="ajouter">

		<h1> Votre Commande </h1>

		<?php
			$larticle=array('marteau'=> 10, 'tennaile' => 5, 'vis' => 5.2, 'clou' => 5.8, 'tournevis' => 7, 'ciseau' => 4, 'toile émeri' => 3);
			$total=0;

			if (isset($_GET['quantite'])){
				$article = $_GET['article'] ;
				$quantite = $_GET['quantite'] ;
				$ajouter = $_GET['ajouter'] ;

				foreach($larticle as $nom => $prix){

					$get_nom = $_GET[$nom];

					if (!empty($get_nom) && strcmp($nom,$article)){
						echo "<input type='hidden' name='$nom' value='$get_nom'>";
						echo "$get_nom $nom = ".$prix*$get_nom."€<br/>";
						$total+=$prix*$get_nom;
					}
				}
				
				if (!empty($ajouter)){
					if ( $quantite != 0){
						echo "$quantite $article = ".$larticle[$article]*$quantite."€ <br/>";
						$total += $larticle[$article]*$quantite;
						echo "<input type='hidden' name='$article' value='$quantite'>";
					}
					else{
						echo "<br/> Erreur : la quantité doit être supérieur à 0";
					}
				}

				echo "<br/> <span style='font-weight:bold'> Total : </span> {$total}€";
			}
		?>
	</form>

</body>

</html>