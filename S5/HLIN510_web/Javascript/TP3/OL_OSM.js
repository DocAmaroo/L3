
//Création de la map
var map = new ol.Map({
    target: "map",
    layers: [new ol.layer.Tile({source: new ol.source.OSM()}) ],
    view: new ol.View({
        center: ol.proj.fromLonLat([3.87667, 43.6111]),
        zoom: 15
    })
})

//Affichage de la popup au clique de l'image
function switchMarker(marker_id){

    // sinon comme Kevinou on faisait un this.id.slice(7) pour virer marker_ au début et puis c'était plus simple xD
    if ( (/marker_+[\w.]/.test(marker_id) )){
        let id = /_(\w+)/.exec(marker_id);
        var popup = document.getElementById("popup_"+id[1]);
        (popup.style.display=="none"? popup.style.display = "block" : popup.style.display = "none");
    }

}

var list_marker = {};
$().ready( function() {

    $.getJSON("JSON/themes.json",function(data_theme){
        $.each(data_theme, function(indice, object_theme){

            let html ="<h3>"+ object_theme.nom +"</h3>\
            <div id='"+object_theme.nom+"'></div>";
            $("#accordion").append(html);
            
            $.getJSON("JSON/"+object_theme.lien, function(data_link){
                $.each(data_link, function(indice, object_link){
                    let html = "<input type='checkbox' name='"+object_link.nom+"'>"+object_link.nom+"</input>";
                    $("#"+object_theme.nom).append(html);
                    
                    /**
                     * Clone marker
                     */
                    let image = $("#markerProto").clone();
                    image.attr("id", "marker_"+object_link.nom);
                    $("body").append(image);

                    var marker = document.getElementById("marker_"+object_link.nom);

                    list_marker[object_link.nom] = 
                        new ol.Overlay({
                        position: ol.proj.fromLonLat([object_link.long, object_link.lat]),
                        element: marker
                    });
                    map.addOverlay(list_marker[object_link.nom]);
                    

                    /**
                     * Clone popup
                     */
                    let popup_clone = $("#popupProto").clone();
                    popup_clone.attr("id", "popup_"+object_link.nom);
                    popup_clone.append("<p>"+object_link.nom+"</p>");
                    $("body").append(popup_clone);

                    var popup = document.getElementById("popup_"+object_link.nom);
                    
                    map.addOverlay(new ol.Overlay({
                        offset: [0, -50],
                        position: ol.proj.fromLonLat([object_link.long, object_link.lat]),
                        element: popup
                    }))
                });
            });

        });
        $("#accordion").accordion({collapsible : true, heightStyle: "content",active:false});
    })

    $("body").on("change", "input[type=checkbox]", function(){
        let valeur = $(this).attr("name");
        var obj = list_marker[valeur];
        if ( $(this).is(":checked") ){
            $("#marker_"+valeur).css("display", "block");
        }
        else{
            $("#marker_"+valeur).css("display", "none");
            $("#popup_"+valeur).css("display", "none");
        }
    });

});