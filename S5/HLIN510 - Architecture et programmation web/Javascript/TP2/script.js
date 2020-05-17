var listeChargees = {};

function generationHTML(objet){ 
    let res = "\
        <ul id='listePrincipal'>\
            <li class='horizontal'> Christophe\
                <img id='albums_Christophe' src='IMAGES/christophe.jpg'/>\
                <ul id='liste_album_Christophe'/>\
            </li>\
            <li class='horizontal'> Demi Roussos\
                <img id='albums_Roussos' src='IMAGES/roussos.jpg'/>\
                <ul id='liste_album_Roussos'/>\
            </li>\
        </ul>";

    return res;
}

function ouvertureFermeterure(){
    var id = $(this).attr('id');
    if ( listeChargees.hasOwnProperty("#liste_"+id)){
        if ( listeChargees["liste_"+id] == 1 ){

        }
        else{

        }
    }
    else{

    }
}

$().ready( function(){
    $("body").append("<ul id='listePrincipal' />");
    $.getJSON('JSON/chanteurs.json', function(data){
        $.each(data, function(indice, objet){
            let html = generationHTML(objet);
            $("#listePrincipal").append(html);
            $(document.body).on('click', '#'+objet.lien, ouvertureFermeterure);
        });
    })
});