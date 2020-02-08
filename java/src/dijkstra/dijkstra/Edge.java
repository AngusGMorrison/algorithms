package dijkstra;

public class Edge implements Comparable<Edge> {
	private Node source;
	private Node destination;
	private Integer weight;
	
	public Edge(Node source, Node destination, Integer weight) {
		this.source = source;
		this.destination = destination;
		this.weight = weight;
	}
	
	public Node getSource() {
		return source;
	}
	
	public Node getDestination() {
		return destination;
	}
	
	public Integer getWeight() {
		return weight;
	}
	
	@Override
	public String toString() {
		return String.format("%s -> %s, %d", source.getName(), destination.getName(), weight);
	}
	
	public int compareTo(Edge other) {
		return weight - other.weight;
	}
}
