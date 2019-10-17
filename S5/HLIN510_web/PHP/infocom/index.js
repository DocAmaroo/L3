function plouf(id){
	document.getElementById(id).value = "~~~~";
}

function boum(id){
	document.getElementById(id).value = "BOUM";
}

NB_BATEAU = 4;
coord_x = new Array([]);
coord_y = new Array([]);

function existe(x, y){
	bool = false;
	for (var i=0; i < coord_x.length; i++){
		if(coord_x[i] == x && coord_y[i] == y){
			bool = true;
		}
	}
	return bool;
}

function createNumberBet1and5(){
	res = Math.floor((Math.random() * 10));
	while( res < 1 || res > 5){
		res = Math.floor((Math.random() * 10));
	}
	return res;
}

function create_coord(){
	i = 0;

	coord_x[i] = createNumberBet1and5();
	coord_y[i] = createNumberBet1and5();
	i++;
	while( i < NB_BATEAU ){
		x = createNumberBet1and5();
		y = createNumberBet1and5();
		while (existe(x, y)){
			x = createNumberBet1and5();
			y = createNumberBet1and5();
		}
		coord_x[i] = x;
		coord_y[i] = y;
		i++;
	}
}

function estBoum(x, y){
	res = false;
	for(var i=0; i<coord_x.length; i++){
		if( coord_x[i] == x && coord_y[i] == y ){
			res = true;
		}
	}

	return res;
}

function init_game(){
	create_coord();
	for(let i=1; i<6; i++){
		for(let j=1; j<6; j++){
			id = "but" + i + "x" + j;
			if( estBoum(i, j) ){
				document.getElementById(id).onclick = function() { boum(this.id); };
			}
			else{
				document.getElementById(id).onclick = function() { plouf(this.id); };
			}
			document.getElementById(id).value = "?"
		}
	}
}