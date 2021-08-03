package udel.src.main.java.com.cthacker.udel;

import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.data.repository.query.Param;
import org.springframework.data.rest.core.annotation.RepositoryRestResource;

@RepositoryRestResource(collectionResourceRel = "oeople", path = "people")
public interface EmployeeRepository extends MongoRepository<Employee,String>{

    List<Employee> findByLastName(@Param("name") String name);

    
}
