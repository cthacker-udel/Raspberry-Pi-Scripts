public import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Inspector {

    public Map<String, String[]> nationRequirements = new HashMap<>();
    public Map<String, String> requiredDocuments = new HashMap<>();
    public Map<String, String> requiredVaccinations = new HashMap<>();
    public Map<String, String> noRequiredVaccinations = new HashMap<>();
    public ArrayList<String> wantedCriminals = new ArrayList<>();
    public String message = "";
    public boolean isValid = true;

    public boolean isValid() {
        return isValid;
    }

    public void setValid(boolean valid) {
        isValid = valid;
    }

    public void receiveBulletin(String bulletin) {

        System.out.println("Bulletin = " + bulletin);

        String[] parts = bulletin.split("\\n");
        for (String eachpart : parts) {
            if (eachpart.contains("Allow")) {
                String[] countries = Stream.of(eachpart.split(" of ")[1].split(",")).map(e -> e.trim()).toArray(String[]::new);
                nationRequirements.put("Allow", countries);
            } else if (eachpart.contains("Deny")) {
                String[] countries = Stream.of(eachpart.split(" of ")[1].split(",")).map(e -> e.trim()).toArray(String[]::new);
                nationRequirements.put("Deny", countries);
            } else if (eachpart.contains("require")){
                String requirement = eachpart.split(" require ")[1];
                String requirerer = eachpart.split(" require ")[0];
                if (requirerer.contains("Citizens")) {
                    if (requirerer.contains(",")) {
                        // multiple citizens
                        String cities = String.join(",",requirerer.split("Citizens of ")[1].split(", "));
                        requiredDocuments.put(cities, requirement);
                    } else {
                        String citizenRequirerer = String.join(",",requirerer.split("Citizens of ")[1].split(", "));
                        if (requirement.contains("no") && requirement.contains("vaccination")) {
                            noRequiredVaccinations.put(citizenRequirerer, requirement);
                        } else if (requirement.contains("vaccination")) {
                            requiredVaccinations.put(citizenRequirerer, requirement);
                        } else {
                            requiredDocuments.put(citizenRequirerer, requirement);
                        }
                    }
                } else if (requirerer.contains("Workers")) {
                    if (requirement.contains("no") && requirement.contains("vaccination")) {
                        noRequiredVaccinations.put("Workers", requirement);
                    } else if (requirement.contains("vaccination")) {
                        requiredVaccinations.put("Workers", requirement);
                    } else {
                        requiredDocuments.put("Workers", requirement);
                    }
                } else if (requirerer.contains("Foreigners")) {
                    if (requirement.contains("no") && requirement.contains("vaccination")) {
                        noRequiredVaccinations.put("Workers", requirement);
                    } else if (requirement.contains("vaccination")) {
                        requiredVaccinations.put("Workers", requirement);
                    } else {
                        requiredDocuments.put("Foreigners", requirement);
                    }
                } else if (requirerer.contains("Entrants")) {
                    if (requirement.contains("no") && requirement.contains("vaccination")) {
                        noRequiredVaccinations.put("Workers", requirement);
                    } else if (requirement.contains("vaccination")) {
                        requiredVaccinations.put("Workers", requirement);
                    } else {
                        requiredDocuments.put("Entrants", requirement);
                    }
                }
            } else if (eachpart.contains("Wanted")) {
                String requirement = eachpart.split("State: ")[1];
                wantedCriminals.add(requirement);
            }
        }

    }

    public boolean checkNationRequirements(String nation) {

        for (Map.Entry<String, String[]> eachNationRequirement : this.nationRequirements.entrySet()) {
            String key = eachNationRequirement.getKey();
            if (key.equals("Allow")) {
                if(Collections.frequency(Arrays.asList(eachNationRequirement.getValue()), nation) >= 1) {
                    return true;
                }
            } else if (key.equals("Deny")) {
                if (Collections.frequency(Arrays.asList(eachNationRequirement.getValue()), nation) >= 1) {
                    return false;
                }
            }
        }
        return true;

    }

    public boolean checkID(String id, Map<String, String> props) {

        if (props.containsKey("ID#")) {
            // already has id
            if (props.get("ID#").equals(id)) {
                return true;
            } else {
                return false;
            }
        }
        return true;

    }

    public boolean checkExpiration(String expiration) {

        System.out.println("in check expiration");
        String[] splitExpiration = expiration.split("\\.");
        int year = Integer.parseInt(splitExpiration[0]);
        int month = Integer.parseInt(splitExpiration[1]);
        int day = Integer.parseInt(splitExpiration[2]);
        if (year <= 1982 && month <= 11 && day <= 22) {
            return false;
        } else if(year <= 1982 && month <= 10) {
            return false;
        }
        return true;
    }

    public boolean checkBaseDocuments(ArrayList<String> documents) {
        // have all documents, now check if they are valid
        if (Collections.frequency(documents, "ID_card") >= 1) {
            return true;
        } else {
            String[] foreignerDocuments = new String[]{ "access_permit", "work_pass", "grant_of_asylum", "diplomatic_authorization"};
            for (String eachDocument : foreignerDocuments) {

                if (Collections.frequency(documents, eachDocument) == 1) {
                    // is foreigner, check requirements
                    String requiredDoc = this.requiredDocuments.get("Foreigners");
                    if (requiredDoc != null && Collections.frequency(documents, requiredDoc) == 0) {
                        return false;
                    }
                }

            }
            if (this.requiredDocuments.containsKey("Entrants")) {
                String requiredDoc = this.requiredDocuments.get("Entrants");
                if (Collections.frequency(documents, requiredDoc) == 0) {
                    this.message = "Entry denied: missing required passport.";
                    this.isValid = false;
                    return false;
                }
            }
            this.isValid = true;
            return true;

        }
    }

    public void checkProperties(Map<String, String> properties) {


        /*

        Nation checker

         */

        String nation = "";

        if (properties.containsKey("NATION")) {
            System.out.println("in if");
            nation = properties.get("NATION");
            if (nation.equals("Arstotzka")) {
                this.message = "Glory to Arstotzka.";
                this.isValid = true;
                return;
            }
            final String tmpNation = nation;
            if (this.nationRequirements.containsKey("Deny")) {
                if (Arrays.stream(this.nationRequirements.get("Deny")).filter(e -> e.contains(tmpNation)).toArray().length > 0) {
                    this.message = "Entry denied: citizen of banned nation.";
                }
                this.setValid(false);
                return;
            } else if (this.nationRequirements.containsKey("Allow")) {
                if (Arrays.stream(this.nationRequirements.get("Allow")).filter(e -> e.contains(tmpNation)).toArray().length > 0) {
                    if (nation.contains("Arstotzka")) {
                        this.message = "Glory to Arstotzka.";
                    } else {
                        this.message = "Cause no trouble.";
                    }
                    this.setValid(true);
                    return;
                } else {
                    this.setValid(false);
                    this.message = "Entry denied: citizen of banned nation.";
                    return;
                }
            } else {
                System.out.println("in else");
                this.setValid(false);
                this.message = "Entry denied: citizen of banned nation.";
                return;
            }
        }

        /*

        Now that we know their citizenship, we can check all required documents

        */
        if (!nation.equals("")) {
            final String tmpNation = nation;
            ArrayList<String> requiredVaccs = this.requiredVaccinations.entrySet().stream().filter(e -> e.getKey().contains(tmpNation) || e.getKey().equals("Entrants")).map(e -> e.getValue()).collect(Collectors.toCollection(ArrayList::new));
            String vaccination = properties.get("");
        }


    }

    public boolean criminalCheck(String name){

        String first = name.split(", ")[1];
        String last = name.split(",")[0];
        String formattedName = first + " " + last;
        System.out.println("in criminal check, and fullname = " + first + " " + last);
        System.out.println("Wanted criminals = " + Arrays.toString(this.wantedCriminals.stream().toArray(String[]::new)));

        for(String eachName : this.wantedCriminals) {
            if (eachName.equalsIgnoreCase(formattedName)) {
                this.message = "Detainment: Entrant is a wanted criminal.";
                this.isValid = false;
                System.out.println("Found criminal");
                return true;
            }
        }
        return false;

    }

    public void printOutProps(Map<String, String> person) {
        System.out.println("nationRequirements: " + this.nationRequirements.entrySet().stream().map(e -> e.getKey() + " : " + Arrays.toString(e.getValue())).collect(Collectors.joining("\n")));
        System.out.println("Person = " + person.entrySet().stream().map(e -> e.getKey() + " : " + e.getValue()).collect(Collectors.joining("\n")));
    }

    public String inspect(Map<String, String> person) {
        this.message = "";
        this.isValid = true;
        Map<String, String> properties = new HashMap<>();

        checkBaseDocuments(new ArrayList<>(person.keySet()));

        if (!this.isValid) {
            return this.message;
        }

        boolean isCriminal = false;
        int faults = 0;
        ArrayList<String> errors = new ArrayList<>();

        for (Map.Entry<String, String> eachEntry: person.entrySet()) {
            String[] splitProperties = eachEntry.getValue().split("\\n");
            for (String eachProp : splitProperties) {
                String propName = eachProp.substring(0, eachProp.indexOf(":"));
                switch (propName) {
                    case "ID#": {
                        String id = eachProp.split("#: ")[1];
                        if (properties.containsKey("ID")) {
                            // compare IDS
                            if (!id.equals(properties.get("ID"))) {
                                return "Detainment: ID number mismatch.";
                            }
                        }
                        properties.put("ID", id);
                        break;
                    }
                    case "NATION": {
                        String nation = eachProp.split(": ")[1];
                        properties.put("NATION", nation);
                        break;
                    }
                    case "NAME": {
                        String name = eachProp.split(": ")[1];
                        if (properties.containsKey("NAME")) {
                            if(!name.equals(properties.get("NAME"))) {
                                return "Detainment: Name mismatch.";
                            }
                        }
                        boolean criminalBool = criminalCheck(name);
                        if (criminalBool) {
                            return this.message;
                        }
                        properties.put("NAME", name);
                        break;
                    }
                    case "DOB": {
                        String dob = eachProp.split(": ")[1];
                        properties.put("DOB", dob);
                        break;
                    }
                    case "SEX": {
                        String sex = eachProp.split(": ")[1];
                        properties.put("SEX", sex);
                        break;
                    }
                    case "PURPOSE": {
                        String purpose = eachProp.split(": ")[1];
                        properties.put("PURPOSE", purpose);
                        break;
                    }
                    case "DURATION": {
                        String duration = eachProp.split(": ")[1];
                        properties.put("DURATION", duration);
                        break;
                    }
                    case "HEIGHT": {
                        String height = eachProp.split(": ")[1];
                        properties.put("HEIGHT", height);
                        break;
                    }
                    case "WEIGHT": {
                        String weight = eachProp.split(": ")[1];
                        properties.put("WEIGHT", weight);
                        break;
                    }
                    case "EXP": {
                        String expiration = eachProp.split(": ")[1];
                        boolean res = checkExpiration(expiration);
                        if (!res) {
                            return "Entry denied: passport expired.";
                        }
                        properties.put("EXP", expiration);
                        break;
                    }
                    case "ISS": {
                        String iss = eachProp.split(": ")[1];
                        properties.put("ISS", iss);
                        break;
                    }
                }
            }
            printOutProps(properties);
            checkProperties(properties);
            if (!this.isValid) {
                return this.message;
            }
        }
        return this.message;

    }

}
class Inspector {
    
}
