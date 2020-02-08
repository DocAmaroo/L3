let liste = [1,2,3,2,'a',1,1];

Array.prototype.nbOcurrences = 
    function(callback){
        let result = {};
        for ( let elem of this ){
            if ( elem in result ){
                result[elem] = ++result[elem];
            }
            else{
                result[elem] = 1;
            }
        }
        for (let i in result){
            callback(i, result[i]);
        }

    }

liste.nbOcurrences(function(e, nb){
    console.log(e+" : "+nb);
});