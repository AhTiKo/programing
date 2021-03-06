package hwk08.employee;

public class Task {
	private String name;
	private double workingHours;

	public Task(String name, double workingHours) {
		setName(name);
		setWorkingHours(workingHours);
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		if (name != null && !name.equals("")) {
			this.name = name;
		} else {
			System.out.println("Name is not valid!");
		}
	}

	public double getWorkingHours() {
		return workingHours;
	}

	public void setWorkingHours(double workingHours) {
		if (workingHours >= 0){
			this.workingHours = workingHours;
		} else {
			System.out.println("WorkingHours is not valid!");
		}
		
	}
}
