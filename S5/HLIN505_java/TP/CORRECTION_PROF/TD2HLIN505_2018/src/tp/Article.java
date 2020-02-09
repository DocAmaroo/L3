package tp;

public class Article extends Document{

/*	public Article() {
	}
*/
	private String journal;

	public Article(String titre, String journal) {
		super(titre);
		this.journal = journal;
	}

	public String getJournal() {
		return journal;
	}
	
	
}
