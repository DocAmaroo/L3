<?php
    $dns = "mysql:host=mysql.etu.umontpellier.fr; dbname=e20160004807; charset=UTF8";
    include "pass.php";
    try{
        $dbh = new PDO( $dns, $login, $pass );
    }
    catch ( PDOException $e ){
        echo $e->getMessage();
    }
?>

<!DOCTYPE html>
<html>

    <head>
        <title> SQL </title>
        <meta charset="utf-8">
    </head>

    <body>

        <h1> <i> Etudiant participant au même stage </i> </h1>

        <table border="3">
            <tr> 
                <th> Numéro </th>
                <th> Sujet </th>
                <th> Responsable </th>
                <th> Tuteur </th>
                <th> Etudiant(s) </th>
            </tr>
            <tr>
                <?php
                $query_stage =
                "SELECT * FROM stagea;";
                $res_stage = $dbh->query($query_stage); 
                foreach( $res_stage as $enr ){
                    echo "<tr> 
                        <td> {$enr['numStageA']} </td>                    
                        <td> {$enr['sujet']} </td>
                        <td> {$enr['respEnt']} </td>                    
                        <td> {$enr['respPeda']} </td>";

                    // On affiche le nom et le prénom de chaque étudiant    
                    $query_etu =
                    "SELECT nom, prenom
                    FROM etudiant
                    WHERE numStageA = ".$enr['numStageA'].";";
                    $res_etu = $dbh->query($query_etu);
                    
                    echo "<td>";
                    foreach( $res_etu as $etu ){
                        echo "{$etu['nom']} {$etu['prenom']} <br/>";
                    }
                    echo " </td> </tr>";
                }
                ?>
            </tr>
        </table>
    </body>
</html>