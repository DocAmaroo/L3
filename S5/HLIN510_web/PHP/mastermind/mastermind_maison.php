<?php 
    session_start();

	if( !isset($_SESSION["to_find"]) || $_POST["reset"]){
        $_SESSION["taille"] = 4;
        $_SESSION["taille-1"] = $_SESSION["taille"]-1;
		$_SESSION["to_find"] = rand(1000,9999);
		$_SESSION["nb_essai"] = 1;
		$_SESSION["bien_place"] = 1;
		$_SESSION["mal_place"] = 1;
        $_SESSION["affichage"] = "
            <tr>
                <td> {$_SESSION['nb_essai']} </td>
                <td> <input type='text' name='choice' pattern='[1-9][0-9]{{$_SESSION['taille-1']}}' size=8> </td>
            </tr>";
    }

    echo "to_find = {$_SESSION['to_find']}";

?>

<!DOCTYPE html>

<html>
    <header>
        <title> Mastermind </title>
        <meta charset="UTF-8">
    </header>

    <body>

        <h1> Mastermind </h1>

        <form method="post">

            <table style="text-align:left">
                <tr>
				    <th> Numéro </th>
				    <th> Proposition </th>
				    <th> Bien placé(s) </th>
				    <th> Mal placé(s) </th>
			    </tr>
                
                <?php 

                    function modEqual($int1, $int2){
                        return ($int1%10 == $int2%10);
                    }

                    /**
                     * Brief : verifie si l'entier donné en paramètre existe dans la solution du mastermind
                     */
                    function existe($int){
                        $temp = $_SESSION["to_find"];

                        $i = 0;
                        while ($i < $_SESSION["taille"]-1) {
                            $nb_to_compare = $temp%10;
                            if ( $nb_to_compare == $int ){
                                return true;
                                echo "trouve";
                            }
                            $temp = (int)($temp/10);
                            $i++;
                        }
                        
                        if( $temp == $int ){
                            return true;
                            echo "trouve";
                        }

                        return false;
                    }

                    /**
                     * Brief : compte le nombre de chiffre bien placé
                     */
                    function get_bien_place( $choice ){
                        /**
                         * Initialisation des variables
                         */
                        $bien_place = 0;
                        $to_find = $_SESSION["to_find"];
                        $choice_copy = $choice;

                        for ($i=0; $i < $_SESSION["taille"]; $i++) { 
                            if( modEqual( $choice_copy, $to_find) ){
                                $bien_place++;
                            }
                            (int)$to_find /= 10;
                            (int)$choice_copy /= 10;
                        }
                        
                        return $bien_place;
                    }

                                        /**
                     * Brief : compte le nombre de chiffre bien placé
                     */
                    function get_mal_place( $choice ){
                        /**
                         * Initialisation des variables
                         */
                        $mal_place = 0;
                        $to_find = $_SESSION["to_find"];
                        $choice_copy = $choice;

                        for ($i=0; $i < $_SESSION["taille"]; $i++) { 
                            if( !modEqual( $choice_copy, $to_find) ){
                                if ( existe( $choice_copy%10 ) ){
                                    $mal_place++;
                                }
                            }
                            (int)$to_find /= 10;
                            (int)$choice_copy /= 10;
                        }
                        
                        return $mal_place;
                    }

                    if ( $_SESSION["nb_essai"] == 1 ){
                        echo "{$_SESSION["affichage"]}";
                        $_SESSION["affichage"] = "";
                    }

                    if ( isset($_POST["envoye"]) ){
                        
                        if ( isset($_POST["choice"]) ){

                            $choice = $_POST["choice"];

                            $last_try = "
                                <tr>
                                    <td> {$_SESSION["nb_essai"]} </td>
                                    <td> {$choice} </td>
                                    <td> ".get_bien_place( $choice )."</td>
                                    <td> ".get_mal_place( $choice )."</td>
                                </tr>";
                        }

                        $_SESSION["nb_essai"]++;

                        $new_try = "
                            <tr>
                                <td> {$_SESSION["nb_essai"]}  </td>
                                <td> <input type='text' name='choice' pattern='[0-9]{{$_SESSION["taille"]}}' size=8> </td>
                            </tr>";
                        
                        $_SESSION["affichage"] = $_SESSION["affichage"].$last_try;
                        echo "{$_SESSION["affichage"]}";
                        echo "$new_try";
                           
                    }
                ?>
            
            </table>


            <input type="submit" name="envoye" value="Envoyer !">
            <input type="submit" name="reset" value="Nouvelle Partie !">
        </form>
    </body>
</html>