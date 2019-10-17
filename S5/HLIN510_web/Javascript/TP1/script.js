function test( noeud ){
    
    var type = "null";
    switch(noeud.nodeType){
        case 1:
            console.log("je suis un element");
            type = "element";
            break;
        case 2:
            console.log("je suis un attribut");
            type = "attribut";
            break;
        case 3:
            console.log("je suis un texte");
            type = "texte";
            break;
        default : 
            console.log("je suis autre chose")
            type = "null";
    }

    console.log(noeud.childNodes);
}


function explorer(){
    var new_div = document.createElement("div"); // <div> </div>
    var text = document.createTextNode("allo"); // "allo"
    new_div.appendChild(text); // <div> allo </div>
    document.body.appendChild(new_div); // rajoute div comme étant un enfant de body
    test(document);
}




// LA POUBELLE


