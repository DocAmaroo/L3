<?php

    /**
     * start the php session
     */
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

    if ( isset($_POST["login"], $_POST["password"], $_POST["connect"]) ){
        // sauvegarde du login dans une var de session
        $_SESSION["login"] = $_POST["login"];

        // la requête sql
        $query = "SELECT * FROM utilisateur U WHERE U.login = '".$_POST["login"]."' AND password = '".md5($_POST["password"])."'";

        // Si dans la requête ont a un seul et unique élément on se connecte
        $res_query = $dbh->query($query);
        if ( $res_query->rowCount() == 1 ){echo "Bienvenue ".$_SESSION["login"]." !";}
        else{echo "Mauvais login ou password !";}
    }

    if ( isset($_POST["disconnect"]) ){
        session_unset();
        echo "Vous avez été déconnecté";
    }
?>
<!DOCTYPE html>

<html lang="fr">
    <head>
        <meta charset="UTF-8">
        <title> Authentification </title>
    </head>

    <body>
        
        <form method="post">
            <input type="text" name="login" placeholder="Login">
            <input type="password" name="password" placeholder="Password">
            <input type="submit" name="connect" value="Se connecter">
            <input type="submit" name="disconnect" value="Deconnexion">
        </form>
    

    </body>
</html>