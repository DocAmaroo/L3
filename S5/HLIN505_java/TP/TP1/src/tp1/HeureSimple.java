package tp1;

public class HeureSimple {
	private int heure;
	private int minute;
	
	private static int granulariteMinutes=5;
	private static int heureMax=22;
	private static int heureMin=7;
	
	
	public int getHeure() {
		return heure;
	}

	public int getMinute() {
		return minute;
	}

	public HeureSimple(int heure, int minute) {
		this.heure = heure;
		this.minute = minute;
		if ( !checkHeure() || !checkMinute()){
			this.heure = -1;
			this.minute = -1;
		}
	}

	public boolean checkHeure(){
		boolean res = true;
		if (heure >= heureMax && heure <= heureMin || heure > 24 || heure < 0){
			res = false;
		}
		return res;
	}

	public boolean checkMinute(){
		boolean res = minute%granulariteMinutes==0;
		if ( heure == heureMax && minute != 0 || minute > 60 || minute < 0) res = false;
		return res;
	}
	
	public String formatHeure(){
		if ( heure < 10 ){
			return "0"+heure;
		}
		else
			return heure+"";
	}
	
	public String formatMinute(){
		if ( minute < 10 ){
			return "0"+minute;
		}
		else
			return minute+"";
	}
	
	@Override
	public String toString() {
		return heure==-1 ? "ERROR" : minute==-1 ? "ERROR" : formatHeure() + ":" + formatMinute();
	}

	
}
