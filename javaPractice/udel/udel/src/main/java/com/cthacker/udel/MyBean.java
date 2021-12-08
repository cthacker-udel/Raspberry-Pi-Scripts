package udel.src.main.java.com.cthacker.udel;

import org.springframework.data.rest.core.annotation.Component;
import org.springframework.data.mongodb.core.MongoTemplate;

@Component
public class MyBean {
    
    private final MongoTemplate mongoTemplate;

    public MyBean(MongoTemplate mongoTemplate){

        this.mongoTemplate = mongoTemplate;

    }

}
