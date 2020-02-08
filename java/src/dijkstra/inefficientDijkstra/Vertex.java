package inefficientDijkstra;

import java.util.Objects;

public class Vertex {
	private final String id;
	
	public Vertex(String id) {
		this.id = id;
	}
	
	public String getId() {
		return id;
	}
	
	@Override
	public boolean equals(Object obj) {
		if (this == obj) return true;
		if (obj == null) return false;
		if (getClass() != obj.getClass()) return false;
		
		Vertex otherVertex = (Vertex) obj;
		return Objects.equals(id, otherVertex.id);
	}
	
	@Override
	public int hashCode() {
		return Objects.hash(id);
	}
	
	@Override
	public String toString() {
		return id;
	}
}
