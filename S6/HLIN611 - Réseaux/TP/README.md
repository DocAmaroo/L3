# Instructions :

1. Connectez-vous à votre session X2GO et ouvrez 2 terminaux
2. Connectez-vous en ssh sur une autre machine :
    ```Bash
    ssh prodpeda-x2go-bionic[number] #[number] un nombre différent de votre machine actuelle
    ```
    <sup>_Donnez votre mot de passe de session habituelle (celui de l'ENT)</sup> <br>
    <sup>Si cela ne fonctionne pas peut-être qu'un autre utilisateur est sur la machine donc changez [number]_</sup>
3. Choississez un des deux terminaux et considéré le dorénavant comme étant votre terminal serveur, l'autre sera le terminal client. Sur votre terminal <em>serveur</em> taper la commande : <code>ifconfig</code> et récupérer l'adresse IP (inet) affiché pour <em>eth0</em> (elle sera de la forme : 162.38.80.x)
4. Sur le terminal serveur exécuté :
    ```bash
    ./serveur [PORT NUMBER]
    ```
    Sur le terminal client exécuté :
    ```bash
    ./client [IP ADRESS] [PORT NUMBER]
    #[IP ADRESS] sera l'adresse récupéré à l'étape 3
    #[PORT NUMBER] le numéro de port ( > 1023 )
    ```