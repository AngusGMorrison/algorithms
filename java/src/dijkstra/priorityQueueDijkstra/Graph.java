package priorityQueueDijkstra;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Graph {
	private Set<Node> nodes;
	
	public Graph(Node... nodes) {
		this.nodes = new HashSet<>(Arrays.asList(nodes));
	}
	
	public Set<Node> getNodes() {
		return Set.copyOf(nodes);
	}
	
	public void addNode(Node node) {
		nodes.add(node);
	}
	
	public boolean removeNode(Node node) {
		return nodes.remove(node);
	}
	
	public void resetNodes() {
		nodes.forEach(node -> node.reset());
	}
}
