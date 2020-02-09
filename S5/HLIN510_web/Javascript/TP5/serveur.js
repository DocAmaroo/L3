var nomsJoueurs = [];
var nbJoueursConnectes = 0;

var serveur = require('http').createServer(function(req, res){});

var io = require("socket.io").listen(serveur);

serveur.listen(8888, function(err) {
    if (err) { return console.log('something bad happened', err); }
    console.log(`server is listening on 8888`)
})

io.sockets.on('connection', function (socket) {
    socket.on('etat', function(message) {
        console.log("Etat d'une partie");
        var etat = {"nbJoueursConnectes":nbJoueursConnectes, "nomsJoueurs":nomsJoueurs};
        socket.emit('etat', etat);
    });

    socket.on('rejoindre',function(message) {
        nomJoueur = message["nomJoueur"];
        console.log("Nouveau joueur : "+nomJoueur);
        nomsJoueurs.push(nomJoueur);
        io.emit('nouveauJoueur', {"numJoueur":nbJoueursConnectes, "nomJoueur":nomJoueur });
        nbJoueursConnectes++;
    });
    
    socket.on('quitter',function(message) {
        numJoueur = message["numJoueur"];
        console.log("Ancien joueur : "+numJoueur);nomsJoueurs.splice(numJoueur, 1);nbJoueursConnectes--;
        io.emit('ancienJoueur', message);
    });

    socket.on('test',function(id, color) {
        io.emit("actionJoueur", id, color);
    });
});