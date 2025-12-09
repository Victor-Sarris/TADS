import express from "express";
import {newObject, listObjects, deleteObject, updateObject } from "./object.controller.js"
import {authenticate, authorizaAdmin} from "../../middleware/authenticate.js"

const objectRouter = express.Router();
objectRouter.get("/objects", authenticate, listObjects)
objectRouter.post("/objects", authenticate,  authorizaAdmin, newObject)
objectRouter.post("/objects/update", authenticate, authorizaAdmin, updateObject)
objectRouter.post("/objects/delete", authenticate, authorizaAdmin, deleteObject)

export default objectRouter; 