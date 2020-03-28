# Instructions :

1. Connectez-vous à votre session X2GO et ouvrez 2 terminaux
2. Connectez-vous en ssh sur une autre machine :
    ```bash
    ssh prodpeda-x2go-bionic[number]
    #[number] un nombre différent de votre machine actuelle
    ```
    <p style="font-size:11px; font-style:italic">Donnez votre mot de passe de session habituelle (celui de l'ENT)</p>
    <p style="font-size:11px; font-style:italic">Si cela ne fonctionne pas peut-être qu'un autre utilisateur est sur la machine donc changez [number]</p>
3. Choississez un des deux terminaux et considéré le dorénavant comme étant votre terminal serveur, l'autre sera le terminal client. <br> Sur votre terminal <em>serveur</em> récupérer l'adresse IP <em>(inet)</em> affiché pour <em>eth0</em> avec la commande <code>ifconfig</code> <small>(elle sera, logiquement, de la forme : 162.38.80.x)</small>
4. Sur le terminal <em>serveur</em> exécuté :
    ```bash
    ./serveur [PORT NUMBER]
    ```
    Sur le terminal <em>client</em> exécuté :
    ```bash
    ./client [IP ADRESS] [PORT NUMBER]
    #[IP ADRESS] sera l'adresse récupéré à l'étape 3
    #[PORT NUMBER] le numéro de port ( > 1023 )
    ```