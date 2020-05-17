window.onload=function(){explorer();}

function test( noeud, dest, indent ){

    if ( noeud == null || noeud == dest ){ return; }
    
    var param = {type : "", color : "", text : ""};
    
    switch(noeud.nodeType){
        case 1:
            param.type = "Element";
            param.color = "#0084FF";
            break;
        case 2:
            param.type = "Attribut";
            param.color = "#FF8100";
            break;
        case 3:
            param.type = "Text";
            param.color = "#0CE8C0";
            param.text = noeud.nodeValue;
            break;
        default : 
            param.type = "Document";
            param.color = "#FFEC00";
    }

    /**
     * On crée une nouvelle division
     */
    var new_div = document.createElement("div");

    /**
     * On ajoute le texte et la couleur de bg dans le div que l'on vient de créer 
     * en indentant au passage avec des "__"
     */
    var textNode = document.createTextNode('');
    for (let i = 0; i < indent; i++) { textNode.appendData("__"); }
    textNode.appendData(param.type + " - " + noeud.nodeName + param.text);
    new_div.appendChild(textNode);
    new_div.style.cssText = "background:"+param.color;

    /**
     * On l'affiche
     */
    dest.appendChild(new_div);

    /**
     * Pour chaque enfant on applique la fonction
     */
    var child = noeud.childNodes;
    for (let i = 0; i < child.length; i++) {
        // console.log(child.item(i).nodeName);
        test( child.item(i), dest, indent++ );
    }
}

function explorer(){
    var new_div = document.createElement("div"); // <div> </div>
    document.body.appendChild(new_div); // rajoute div comme étant un enfant de body
    test(document, new_div, 0);
}


