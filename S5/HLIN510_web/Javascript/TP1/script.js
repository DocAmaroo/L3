/**
 * @type       Javascript
 * @file       script.js of index.html
 * @author     Canta Thomas <thomas.canta@ent.umontpellier.fr>
 * @repo 	   https://gitlab.info-ufr.univ-montp2.fr/Maxime/Humeur_de_tweet
*/

function explorer(){
    var new_div = document.createElement("div");
    // var text = document.createTextNode("allo");
    // new_div.appendChild(text);

    new_div.textContent = "allo";
    document.body.appendChild(new_div);
}