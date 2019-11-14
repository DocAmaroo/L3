/**
 * Transform degrees to radian
 * @param {int} deg 
 */
function degToRadian(deg){
    return Math.PI*deg/180;
}

/**
 * Create the 'points' attribut, like for an hexagon
 * @param {Array[Array[]...]} points 
 */
function createHexagonAttr(points){
    var attr_points = "";

    for ( pts of points ){
        attr_points += pts[0]+","+pts[1]+" ";
    }

    return attr_points;
}

/**
 * Return the max horizontal (x) coord on the points list
 * @param {Array[Array[]...]} points 
 */
function getMaxHorizontalCoord(points){
    var max_x = 0;

    for ( pts of points ){
        max_x = Math.max(pts[0], max_x);
    }

    return max_x;
}

/**
 * Modify all horizontal (x) points by adding int for each of them
 * @param {Array[Array[]...]} points 
 * @param {int} int
 * @returns The modify array
 */
function modifyHorizontalCoord(points, int){
    for( pts of points ){
        pts[0] = pts[0] + int;
    }
    return points;
}

/**
 * Modify all vertical (y) points by adding int for each of them
 * @param {Array[Array[]...]} points 
 * @param {int} int 
 */
function modifyVerticalCoord(points, int){
    for( pts of points ){
        pts[1] = pts[1] + int;
    }
    return points;
}

/**
 * Return the coordinate of the first hexagon
 * @param {int} rayon 
 */
function getCoordHexaProto(rayon){

    var diametre = rayon*2;
    var points = new Array(), angle;

    for ( let i = 0; i < 6; i++ ){
        angle = degToRadian(60*(i+1));
        var x = Math.sin(angle)*rayon;
        var y = -Math.cos(angle)*rayon;

        x = Math.round(x*100)/100;
        y = Math.round(y*100)/100;

        points.push(new Array(x+rayon,y+rayon));
    }
    return points;
}

/**
 * generate the hive
 * @param {int} rayon 
 * @param {int} nbLig 
 * @param {int} nbCol 
 */
function generateHive(rayon, nbLig, nbCol){

    var points = getCoordHexaProto(rayon);
    var max_x = getMaxHorizontalCoord(points);
    var attr_points = "";
    var diametre = rayon*2, tmp_nbCol = nbCol, color = "";

    /**
     * horizontal & vertical space between each hexagon
     */
    var h_space_between = max_x, v_space_between = diametre/1;

    d3.select("#ruche")
    .append("svg")
    .attr("width", diametre*nbCol)
    .attr("height", diametre*nbLig);

    for( let l=0; l < nbLig; l++ ){

        /**
         * recreate coordinate each new line
         */
        points = getCoordHexaProto(rayon);

        /**
         * Modify vertical (y) value of each point each new line
        */
        if ( l != 0 ){ points = modifyVerticalCoord(points, v_space_between*l); }
        
        /**
         * if odd line :
         * Create one less hexagon
         * Modify hexagon color ( gray -> black )
         * Modify horizontal (x) value of each point
         */
        if ( !(l%2 == 0) ){ 
            tmp_nbCol = nbCol-1;
            color = "black";
            points = modifyHorizontalCoord(points, rayon);
        }
        else { color = "gray"; tmp_nbCol = nbCol; }

        /**
         * recreate the new 'points' attribut
         */
        attr_points = createHexagonAttr(points);

        for ( let c=0; c < tmp_nbCol; c++ ){

            d3.select("#ruche > svg")
            .append("polygon")
            .attr("id", "hexa_"+l+c)
            .attr("points", attr_points)
            .style("fill", color)
            .on("mouseover", function(){
                d3.select(this)
                .style("fill", "red");
            })
            .on("mouseout", function(){
                d3.select(this)
                .style("fill", "green");
                
            });
            points = modifyHorizontalCoord(points, h_space_between);
            attr_points = createHexagonAttr(points);
            
        }
    }
}