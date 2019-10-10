<?php
    // start de session
    session_start();

    // SQL
    $dns = "mysql:host=mysql.etu.umontpellier.fr; dbname=e20160004807; charset=UTF8";
    include "pass.php";
    try{
        $dbh = new PDO( $dns, $login, $pass );
    }
    catch ( PDOException $e ){
        echo $e->getMessage();
    }

    // variable de session
    if ( isset($_POST["send"]) ){
        $option = $_POST["option"];
        $order = $_POST["order"];
        $query = "";
    }

    if ( isset($_POST["reset"]) ){
        session_unset();
    }
?>

<!DOCTYPE html>

<html>
    <header> 
        <title> Trombinoscope  </title>
        <meta charset="utf-8">
    </header>

    <body>
        <h1> Trombinoscope </h1>
        
        <form method="POST">
            <select multiple size="5" name="option[]">
                <?php
                    $query_option =
                    "SELECT DISTINCT nom, code FROM options;";
                    $res_option = $dbh->query($query_option);
                    
                    foreach( $res_option as $key_option ){
                        echo "<option value=".$key_option["code"].">".$key_option["nom"]."</option>";
                    }
                ?>
            </select>

            <select name="order">
                <option value="nom"> Nom </option>
                <option value="prenom"> Prénom </option>
                <option value="statut"> Statut </option>
                <option value="groupe"> Groupe </option>
                <option value="opt"> Options </option>
            </select>

            <input type="submit" name="send" value="Envoyer !">
            <input type="submit" name="reset" value="Reset !">
        </form>

        <?php 
            $query = "SELECT * FROM etudiant e";
            // "SELECT e.nom, prenom, statut, groupe, o.nom, e.numStageA 
            // FROM etudiant e LEFT JOIN options o ON e.opt=o.code";

            if ( !empty($_POST['option']) && $nbopt=count($_POST['option']) ){
                $ensemble="('{$_POST['option'][0]}'" ;
                for ($i=1;$i<$nbopt;$i++){
                    $ensemble.=",'{$_POST['option'][$i]}'";
                }
                $query.= " WHERE e.opt IN $ensemble) ";
            }
            if ( !empty($_POST['order'] )){
                switch ($_POST['order']){	 
                    case "opt" : $query.= "ORDER BY optnom, nom, prenom;";break;
                    case "groupe" : $query.= "ORDER BY groupe, nom, prenom;";break;
                    case "statut" : $query.= "ORDER BY statut, nom, prenom;";break;
                    default : $query.= "ORDER BY nom, prenom;";break;
                }
            }
            else{ $query.= "ORDER BY nom, prenom;";}

            //echo $query;
            echo $query;
            $final_query = $dbh->query($query) or die("Requete impossible !");
            echo "<tabme>"
            foreach( $final_query as $key ){
                echo "<tr> 
                    <td> {$key['numStageA']} </td>
        ?>
    </body>
</html>