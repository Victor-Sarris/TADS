import express from "express";
import {newPerson, listPersons, deletePerson, updatePerson } from "./person.controller.js"
import {authenticate, authorizaAdmin} from "../../middleware/authenticate.js"

const personRouter = express.Router();
personRouter.get("/people", authenticate, listPersons)
personRouter.post("/people", authenticate,  authorizaAdmin, newPerson)
personRouter.post("/people/update", authenticate, authorizaAdmin, updatePerson)
personRouter.post("/people/delete", authenticate, authorizaAdmin, deletePerson)

export default personRouter; 